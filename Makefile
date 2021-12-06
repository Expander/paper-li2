NAM := paper
TEX := $(NAM).tex
PDF := $(NAM).pdf
BIB := $(NAM).bib
BBL := $(NAM).bbl
TAR := $(NAM).tar.gz
SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)

all: $(PDF)

arxiv: $(TAR)
	@true

test-arxiv: arxiv
	-rm -rf paper
	tar -xf paper.tar.gz
	cd paper && pdflatex paper.tex && pdflatex paper.tex
	-rm -rf paper

clean:
	latexmk -c
	-rm -f $(OBJ)

distclean: clean
	latexmk -C

compile: $(OBJ)
	@true

$(PDF): $(TEX) $(BIB)
	latexmk $(TEX)

$(TAR): $(TEX) $(BIB) $(BBL) $(SRC) | all
	tar --transform 's,^,paper/,' -czf $@ $^

%.o: %.c
	$(CC) -O2 -c $< -o $@
