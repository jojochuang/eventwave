FILE(REMOVE_RECURSE
  "CMakeFiles/parsers"
  "MaceHeaderRecDescent.pm"
  "MaceRecDescent.pm"
  "ClassParserRecDescent.pm"
  "VariantRecDescent.pm"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/parsers.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
