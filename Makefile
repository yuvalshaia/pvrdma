KVERSION ?= $(shell uname -r)
KDIR ?= /lib/modules/${KVERSION}/build
version ?= 1.0
TAG ?= HEAD

modules:
	$(MAKE) -C $(KDIR) M=$$PWD modules

modules_install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -rf buildrpm/*.tar.bz2 buildrpm/rpm

archive:
	mkdir buildrpm/kibpingpong-$(version)
	cp -a Makefile Kbuild drivers include buildrpm/kibpingpong-$(version)
	make -C buildrpm/kibpingpong-$(version) clean
	tar jcf buildrpm/kibpingpong-$(version).tar.bz2 -C buildrpm kibpingpong-$(version)
	rm -rf buildrpm/kibpingpong-$(version)

archive-rpm: archive rpm

git-archive:
	git archive --prefix=kibpingpong-$(version)/ $(TAG) . | \
		bzip2 > buildrpm/kibpingpong-$(version).tar.bz2

git-rpm: git-archive rpm

rpm:
	mkdir -p buildrpm/rpm/{RPMS,BUILD{,ROOT},SRPMS}
	cd buildrpm; rpmbuild \
		"--define=kversion $(KVERSION)" \
		"--define=_topdir $$PWD/rpm" \
		"--define=_sourcedir $$PWD" \
		"--define=_specdir $$PWD" \
		"--define=_tmppath $$PWD/rpm/BUILDROOT" \
		-ba kibpingpong-kmod-el6.spec

.PHONY: modules modules_install clean archive archive-rpm git-archive git-rpm rpm
