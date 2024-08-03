/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Name of package */
#define PACKAGE "powermanga"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "http://sf.net/projects/powermanga/bugs"

/* Define to the full name of this package. */
#define PACKAGE_NAME "Powermanga"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "Powermanga 0.94.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "powermanga"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.94.0"

/* Enable option to export sprites to PNG) */
#define PNG_EXPORT_ENABLE 1

/* Define to enable SDL support */
#define POWERMANGA_SDL 1

/* Define to enable X11 support */
/* #undef POWERMANGA_X11 */

/* Define to 1 if all of the C89 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Define to enable development version */
/* #undef UNDER_DEVELOPMENT */

/* Define to use a malloc wrapper */
/* #undef USE_MALLOC_WRAPPER */

/* Enable sound (SDL Mixer) */
#define USE_SDLMIXER 1

/* Version number of package */
#define VERSION "0.94.0"

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported only directly.  */
#define restrict __restrict__
/* Work around a bug in older versions of Sun C++, which did not
   #define __restrict__ or support _Restrict or __restrict__
   even though the corresponding Sun C compiler ended up with
   "#define restrict _Restrict" or "#define restrict __restrict__"
   in the previous line.  This workaround can be removed once
   we assume Oracle Developer Studio 12.5 (2016) or later.  */
#if defined __SUNPRO_CC && !defined __RESTRICT && !defined __restrict__
# define _Restrict
# define __restrict__
#endif
