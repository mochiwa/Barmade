#ifndef BMLIB_GLOBAL_H
#define BMLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BMLIB_LIBRARY)
#  define BMLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BMLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BMLIB_GLOBAL_H
