NAM := paper
TEX := $(NAM).tex
PDF := $(NAM).pdf
BIB := $(NAM).bib
BBL := $(NAM).bbl
TAR := $(NAM).tar.gz

all: $(PDF)

arxiv: $(TAR)
	@true

clean:
	latexmk -c

distclean:
	latexmk -C

$(PDF): $(TEX) $(BIB)
	latexmk $(TEX)

$(TAR): $(TEX) $(BIB) $(BBL)| all
	tar --transform 's,^,paper/,' -czf $@ $^
