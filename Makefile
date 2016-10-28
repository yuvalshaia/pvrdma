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
	mkdir buildrpm/pvrdma-$(version)
	cp -a Makefile Kbuild drivers include buildrpm/pvrdma-$(version)
	make -C buildrpm/pvrdma-$(version) clean
	tar jcf buildrpm/pvrdma-$(version).tar.bz2 -C buildrpm pvrdma-$(version)
	rm -rf buildrpm/pvrdma-$(version)

archive-rpm: archive rpm

git-archive:
	git archive --prefix=pvrdma-$(version)/ $(TAG) . | \
		bzip2 > buildrpm/pvrdma-$(version).tar.bz2

git-rpm: git-archive rpm

rpm:
	mkdir -p buildrpm/rpm/{RPMS,BUILD{,ROOT},SRPMS}
	cd buildrpm; rpmbuild \
		"--define=kversion $(KVERSION)" \
		"--define=_topdir $$PWD/rpm" \
		"--define=_sourcedir $$PWD" \
		"--define=_specdir $$PWD" \
		"--define=_tmppath $$PWD/rpm/BUILDROOT" \
		-ba pvrdma-kmod-el6.spec

.PHONY: modules modules_install clean archive archive-rpm git-archive git-rpm rpm
