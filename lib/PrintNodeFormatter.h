#ifndef __PRINT_NODE_FORMATTER_H
#define __PRINT_NODE_FORMATTER_H

#include "Printable.h"

namespace mace {
  class PrintNodeFormatter {
  public:

    static bool containsMap(const PrintNode& node) {
      if (node.getType().find("map<") == 0) {
	return true;
      }
      const PrintNodeList& l = node.getChildren();
      bool r = false;
      for (PrintNodeList::const_iterator i = l.begin();
	   i != l.end() && !r; i++) {
	r |= containsMap(*i);
      }
      return r;
    }

    static void printStruct(std::ostream& out, const PrintNode& node,
			    size_t indent,
			    bool printName,
			    bool parentFlatten) {
//       out << "printStruct " << node.getName() << " " << node.getType() << std::endl;
      bool flatten = parentFlatten || !containsMap(node);
      if (printName) {
	out << node.getName();
	if (flatten) {
	  out << "(";
	}
	else {
	  out << "(" << std::endl;
	}
      }
      else {
	out << "(";
      }

      const PrintNodeList& l = node.getChildren();
      PrintNodeList::const_iterator i = l.begin();
      while (i != l.end()) {
	if (!flatten) {
	  spaces(out, indent + 2);
	}
	print(out, *i, indent + 2, true, flatten);
	bool wasMap = isMap(*i);
	i++;
	if (flatten) {
	  if (i != l.end()) {
	    if (wasMap || isMap(*i)) {
	      out << std::endl;
	      spaces(out, indent + 2);
	    }
	    else {
	      out << " ";
	    }
	  }
	  else {
	    out << ")";
	  }
	}
	else if (i != l.end()) {
	  out << std::endl;
	}
      }
      if (!flatten) {
	spaces(out, indent);
	out << ") //" << node.getName() << std::endl;
      }
    } // printStruct

    static void printMap(std::ostream& out, const PrintNode& node,
			 size_t indent,
			 bool printName,
			 bool parentFlatten) {
      if (printName) {
	out << node.getName() << ":";
      }
      const PrintNodeList& l = node.getChildren();
      if (l.empty()) {
	out << " ()";
	return;
      }
      else {
	if (printName) {
	  out << std::endl;
	}
      }
      PrintNodeList::const_iterator i = l.begin();
      while (i != l.end()) {
	if (printName || i != l.begin()) {
	  spaces(out, indent + 2);
	}
	print(out, *i, indent + 2, false, true);
	i++;
	out << "->";
	if (containsMap(*i)) {
	  out << std::endl;
	  spaces(out, indent + 4);
	  print(out, *i, indent + 4, false, true);
	}
	else {
	  print(out, *i, indent + 2, false, true);
	}
	i++;
	if (i != l.end()) {
	  out << std::endl;
	}
      }
    } // printMap

    static void printList(std::ostream& out, const PrintNode& node,
			  size_t indent,
			  bool printName) {
      if (printName) {
	out << node.getName() << "=";
      }
      out << "[";
      const PrintNodeList& l = node.getChildren();
      PrintNodeList::const_iterator i = l.begin();
      while (i != l.end()) {
	print(out, *i, 0, false);
	i++;
	if (i != l.end()) {
	  out << " ";
	}
      }
      out << "]";
    } // printList

    static void printValue(std::ostream& out, const PrintNode& node,
			   bool printName, bool flatten) {
      if (printName) {
	if (flatten) {
	  out << formatName(node.getName()) << "=";
	}
	else {
	  out << node.getName() << "=";
	}
      }
      if (node.getValue() == "true") {
	out << "1";
      }
      else if (node.getValue() == "false") {
	out << "0";
      }
      else {
	out << node.getValue();
      }
    } // printValue

    static void print(std::ostream& out,
		      const PrintNode& node,
		      size_t indent = 0,
		      bool printName = true,
		      bool parentFlatten = false) {
//       out << "print " << node.getName()
// 	  << "<" << node.getType() << ">" << std::endl;
      if (isMap(node)) {
// 	out << "*printMap" << std::endl;
	printMap(out, node, indent, printName, parentFlatten);
      }
      else if (node.getType().find("set<") == 0 ||
	       node.getType().find("list<") == 0) {
// 	out << "*printList" << std::endl;
	printList(out, node, indent, printName);
      }
      else if (!node.getValue().empty() || node.getChildren().empty()) {
// 	out << "*printValue" << std::endl;
	printValue(out, node, printName, parentFlatten);
      }
      else {
// 	out << "*printStruct" << std::endl;
	printStruct(out, node, indent, printName, parentFlatten);
      }
    } // print

    static std::string formatName(const std::string& name) {
      return name.substr(0, 4);
    }

    static bool isMap(const PrintNode& node) {
      return node.getType().find("map<") == 0;
    }

    static void printWithTypes(std::ostream& out, const PrintNode& node,
			       size_t indent = 0) {
      spaces(out, indent);
      out << "[" << node.getName() << "<" << node.getType() << ">";
      if (!node.getValue().empty()) {
	out << " = " << node.getValue() << "]";
      }
      else {
	const PrintNodeList& l = node.getChildren();
	if (!l.empty()) {
	  out << std::endl;
	  for (PrintNodeList::const_iterator i = l.begin(); i != l.end(); i++) {
	    printWithTypes(out, *i, indent + 2);
	  }
	  spaces(out, indent);
	}
	out << "]";
      }
      out << std::endl;
    } // printWithTypes

    static void spaces(std::ostream& out, size_t sz) {
      for (size_t i = 0; i < sz; i++) {
	out << " ";
      }
    }

  };
};

#endif // __PRINT_NODE_FORMATTER_H
