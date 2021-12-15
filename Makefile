NAM := paper
TEX := $(NAM).tex
PDF := $(NAM).pdf
BIB := $(NAM).bib
BBL := $(NAM).bbl
STY :=
TAR := $(NAM).tar.gz
SRC := $(wildcard src/log1p_*.c) anc/Li2.c
OBJ := $(SRC:.c=.o)
LIB := src/log1p.a
TST := src/test_log1p.x
BNC := src/bench_log1p.x

all: $(PDF)

arxiv: $(TAR)
	@true

clean:
	latexmk -c
	-rm -f $(OBJ) $(LIB) $(TST) $(BNC)

distclean: clean
	latexmk -C

compile: $(OBJ)
	@true

bench: $(BNC)
	$<

test: $(TST)
	$<

test-arxiv: arxiv
	-rm -rf $(NAM)
	tar -xf $(TAR)
	cd $(NAM) && pdflatex $(NAM).tex && pdflatex $(NAM).tex
	-rm -rf $(NAM) $(TAR)

$(PDF): $(TEX) $(BIB) $(SRC) $(STY)
	latexmk $(TEX)

$(TAR): $(TEX) $(BIB) $(BBL) $(SRC) $(STY) | all
	tar --transform 's,^,paper/,' -czf $@ $^

%.o: %.c
	$(CC) -O2 -c $< -o $@

%.x: %.o $(LIB)
	$(CC) -O2 $^ -o $@ -lm

$(LIB): $(OBJ)
	ar r $@ $^
