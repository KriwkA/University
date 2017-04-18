#ifndef RIS_GLOBAL_H
#define RIS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RIS_LIBRARY)
#  define RISSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RISSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RIS_GLOBAL_H
