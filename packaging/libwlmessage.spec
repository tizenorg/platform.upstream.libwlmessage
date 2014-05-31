%bcond_with wayland

Name:           libwlmessage
Version:        0.1
Release:        1
Summary:        A library to display messages or dialog boxes under Wayland
License:        MIT
Group:          Graphics & UI Framework/Wayland Window System
Url:            https://github.com/Tarnyko/libwlmessage.git

Source0:         %name-%version.tar.xz
Source1: 	libwlmessage.manifest
BuildRequires:	autoconf >= 2.64, automake >= 1.11
BuildRequires:  libtool >= 2.2
BuildRequires:  libjpeg-devel
BuildRequires:  xz
BuildRequires:  pkgconfig
BuildRequires:  pkgconfig(libpng)
BuildRequires:  pkgconfig(xkbcommon)
BuildRequires:  pkgconfig(wayland-client)
BuildRequires:  pkgconfig(wayland-cursor)
BuildRequires:  pkgconfig(wayland-egl)
BuildRequires:  pkgconfig(egl)
BuildRequires:  pkgconfig(glesv2)
BuildRequires:  pkgconfig(pixman-1)
BuildRequires:  pkgconfig(cairo)
BuildRequires:  pkgconfig(cairo-egl)
BuildRequires:  pkgconfig(cairo-glesv2)
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(gio-2.0)

%if !%{with wayland}
ExclusiveArch:
%endif

%description
A library to display messages or dialog boxes under Wayland.

%package devel
Summary:	Development components for the %{name} package.
Group:		Development/Libraries
Requires:	%{name} = %{version}

%description devel
Development files for %{name}

%prep
%setup -q
cp %{SOURCE1} .

%build
%reconfigure
make %{?_smp_mflags}

%install
%make_install
# install binaries

%files
%manifest %{name}.manifest
%defattr(-,root,root)
%license COPYING
%{_libdir}/*.so.*

%files devel
%manifest %{name}.manifest
%defattr(-,root,root)
%{_includedir}/libwlmessage.h
%{_libdir}/*.so
%{_libdir}/pkgconfig/*.pc

%changelog
