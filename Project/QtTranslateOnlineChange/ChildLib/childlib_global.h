#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CHILDLIB_LIB)
#  define CHILDLIB_EXPORT Q_DECL_EXPORT
# else
#  define CHILDLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define CHILDLIB_EXPORT
#endif
