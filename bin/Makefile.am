## include the README file
EXTRA_DIST = README

## override the 'all' target for the make
all:
	## link to the programs that are generated
	rm -rf ./ans*
	ln -s $(top_builddir)/src/c/ans* .
	ln -s $(top_builddir)/src/cc/ans* .
	##ln -s $(top_builddir)/src/c/ans3 

clean:
	rm -rf ./ans*
