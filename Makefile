NAM := paper
TEX := $(NAM).tex
PDF := $(NAM).pdf
BIB := $(NAM).bib
BBL := $(NAM).bbl
TAR := $(NAM).tar.gz
SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
TST := src/test_log1p.x

all: $(PDF)

arxiv: $(TAR)
	@true

clean:
	latexmk -c
	-rm -f $(OBJ)

distclean: clean
	latexmk -C

compile: $(OBJ)
	@true

test: $(TST)
	$<

test-arxiv: arxiv
	-rm -rf paper
	tar -xf paper.tar.gz
	cd paper && pdflatex paper.tex && pdflatex paper.tex
	-rm -rf paper

$(PDF): $(TEX) $(BIB) $(SRC)
	latexmk $(TEX)

$(TAR): $(TEX) $(BIB) $(BBL) $(SRC) | all
	tar --transform 's,^,paper/,' -czf $@ $^

%.o: %.c
	$(CC) -O2 -c $< -o $@

%.x: $(OBJ)
	$(CC) -O2 $^ -o $@ -lm
