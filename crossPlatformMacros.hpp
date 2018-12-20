//because windows sucks...

#ifndef ESSENTIALQTGSO_CROSSPLATFORMMACROS_HPP
#define ESSENTIALQTGSO_CROSSPLATFORMMACROS_HPP

#include <QtCore/QtGlobal>

//remember to define this variable in the .pro file
#if defined(ESSENTIALQTGSO_LIBRARY)
#  define EXPIMP_ESSENTIALQTGSO Q_DECL_EXPORT
#else
#  define EXPIMP_ESSENTIALQTGSO Q_DECL_IMPORT
#endif

#endif // ESSENTIALQTGSO_CROSSPLATFORMMACROS_HPP
