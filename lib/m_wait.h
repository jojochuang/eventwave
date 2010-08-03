#include "maceConfig.h"

/**
 * \file m_wait.h
 * \brief File to include instead of sys/wait.h for portability.
 */

#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif
