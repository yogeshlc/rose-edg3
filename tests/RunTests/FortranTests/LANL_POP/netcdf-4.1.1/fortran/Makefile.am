## This is an automake file, part of Unidata's netCDF package.
# Copyright 2005, see the COPYRIGHT file for more information.

## This file controls the building of the fortran convenience library.

# $Id: Makefile.am,v 1.55 2009/12/27 13:24:00 ed Exp $

AM_CPPFLAGS =
AM_LDFLAGS =

# The F77 API man page.
#man_MANS = netcdf_f77.3     # ROSE POP TEST
man_MANS =

# This rule generates the F77 manpage.
ARGS_MANPAGE = -DAPI=FORTRAN
if USE_NETCDF4
ARGS_MANPAGE += -DNETCDF4=TRUE
endif
if BUILD_DAP
ARGS_MANPAGE += -DDAP=TRUE
endif
if BUILD_PARALLEL
ARGS_MANPAGE += -DPARALLEL_IO=TRUE
endif
netcdf_f77.3:

# Does the user wants separate fortran libraries? See the comments in
# libsrc/Makefile.am about the version-info number.
if BUILD_SEPARATE_FORTRAN
lib_LTLIBRARIES = libnetcdff.la
# Point pre-processor and linker to directory with C lib.
AM_CPPFLAGS += -I$(NETCDF_C_LIB)/include
AM_LDFLAGS += -L$(NETCDF_C_LIB)/lib
else
noinst_LTLIBRARIES = libnetcdff.la
endif

# These are the source files for the fortran library.
libnetcdff_la_SOURCES = fort-attio.c fort-control.c fort-dim.c		\
fort-genatt.c fort-geninq.c fort-genvar.c fort-lib.c fort-misc.c	\
fort-v2compat.c fort-vario.c fort-var1io.c fort-varaio.c fort-varmio.c	\
fort-varsio.c cfortran.h fort-lib.h ncfortran.h

# Tell make to install this as a header file.
nodist_include_HEADERS = netcdf.inc

# The include file and man page are both built by make.
#BUILT_SOURCES = netcdf.inc netcdf_f77.3    # ROSE POP TEST
BUILT_SOURCES = netcdf.inc

netcdf.inc: netcdf2.inc netcdf3.inc netcdf4.inc nfconfig.inc
	echo '!     NetCDF-3.' > netcdf.inc
	cat @top_srcdir@/fortran/netcdf3.inc >> netcdf.inc
if BUILD_V2
	echo >> netcdf.inc
	echo '!     NetCDF-2.' >> netcdf.inc
	cat @top_srcdir@/fortran/netcdf2.inc >> netcdf.inc
endif
if USE_NETCDF4
	echo >> netcdf.inc
	echo '!     NetCDF-4.' >> netcdf.inc
	cat @top_srcdir@/fortran/netcdf4.inc >> netcdf.inc
endif
if USE_LOGGING
	echo >> netcdf.inc
	echo '!     This is to turn on netCDF internal logging.' >> netcdf.inc
	echo '      integer nf_set_log_level' >> netcdf.inc
	echo '      external nf_set_log_level' >> netcdf.inc
endif

# Tell make to rebuld fortran library if nfconfig.inc has changed
# (it's generated by the configure script from nfconfig.in), or if
# netcdf.inc has changed.
libnetcdff_la_DEPENDENCIES = nfconfig.inc netcdf.inc 

# May need to set this.
libnetcdff_la_LIBADD = 

# Is the user building netCDF-4?
if USE_NETCDF4

# All netCDF-4 F77 functions are in one code file.
libnetcdff_la_SOURCES += fort-nc4.c

if BUILD_SEPARATE_FORTRAN
# Fortran library depends on C library.
libnetcdff_la_LIBADD += $(top_builddir)/libsrc4/libnetcdf.la

#libnetcdff_la_LDFLAGS = $(AM_LDFLAGS) -version-info 5:0:0 -no-undefined
libnetcdff_la_LDFLAGS = $(AM_LDFLAGS) -version-info 5:0:0 
endif # BUILD_SEPARATE_FORTRAN

# Find netCDF header file in libsrc4.
AM_CPPFLAGS += -I$(top_srcdir)/libsrc4

# If the user specified a root for HDF5, use it.
if USE_HDF5_DIR
AM_CPPFLAGS += -I@HDF5DIR@/include
AM_LDFLAGS += -L@HDF5DIR@/lib
endif

# If the user specified a root location for HDF4, use it.
if USE_HDF4_DIR
AM_CPPFLAGS += -I@HDF4DIR@/include
AM_LDFLAGS += -L@HDF4DIR@/lib
endif

# If the user specified a root location for ZLIB, use it.
if USE_ZLIB_DIR
AM_CPPFLAGS += -I@ZLIBDIR@/include
AM_LDFLAGS += -L@ZLIBDIR@/lib
endif

# If the user specified a root location for SZLIB, use it.
if USE_SZLIB_DIR
AM_CPPFLAGS += -I@SZLIBDIR@/include
AM_LDFLAGS += -L@SZLIBDIR@/lib
endif

# If the user specified a root location for pnetcdf, use it.
if USE_PNETCDF_DIR
AM_CPPFLAGS += -I@PNETCDFDIR@/include
AM_LDFLAGS += -L@PNETCDFDIR@/lib
endif

else # not USE_NETCDF4

# Find netCDF header file in libsrc.
AM_CPPFLAGS += -I$(top_srcdir)/libsrc

if BUILD_SEPARATE_FORTRAN
# Fortran library depends on C library.
libnetcdff_la_LIBADD += $(top_builddir)/libsrc/libnetcdf.la

libnetcdff_la_LDFLAGS = $(AM_LDFLAGS) -version-info 4:0:0 
endif # BUILD_SEPARATE_FORTRAN

endif # USE_NETCDF4

# If F90 is built, include it's convenience library.
if BUILD_F90
libnetcdff_la_LIBADD += ../f90/libnetcdff90.la
nodist_EXTRA_libnetcdff_la_SOURCES = dummy.f90
endif

# If we are building the dll (under MinGW) then set the correct flags.
if BUILD_DLL
AM_CPPFLAGS += -DNC_DLL_EXPORT
#libnetcdff_la_LDFLAGS = += -no-undefined
endif

if BUILD_DAP
AM_CPPFLAGS += @CURL_CFLAGS@
AM_LDFLAGS += @CURL_LIBS@
endif

# The nfconfig.in file is turned into nfconfig.inc by the configure
# script. The man page is generated on the developers machine for the
# dist.
EXTRA_DIST = nfconfig.in $(man_MANS) netcdf2.inc netcdf3.inc	\
netcdf4.inc

# These files need to be cleaned up my make.
CLEANFILES = nfconfig1.inc netcdf.inc
DISTCLEANFILES = nfconfig.inc 

test: check
