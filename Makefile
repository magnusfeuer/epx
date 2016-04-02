#
#
#
release:
	(cd c_src; $(MAKE) -j4 release)
	(cd tools; $(MAKE))

debug:
	(cd c_src; $(MAKE) -j4 debug)
	(cd tools; $(MAKE))

clean:
	(cd c_src; $(MAKE) clean)
	(cd tools; $(MAKE) clean)

spotless:
	(cd c_src; $(MAKE) clean)
	(cd tools; $(MAKE) clean)
