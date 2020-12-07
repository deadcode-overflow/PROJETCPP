PART_ONE=PARTIE_1
PART_TWO=PARTIE_2
PART_THREE=PARTIE_3

.PHONY : clean clean_project clean_Qt_build project qt_build

# Generate all from all parts
all: project qt_build

# Compile project from all parts - (part 2 and 3 not finish)
project:
	$(MAKE) -C $(PART_ONE) project
	$(MAKE) -C $(PART_TWO) project
	@echo "\nall project generated"

# Create Qt build  from all parts - (part 2 and 3 not finish)
qt_build:
	$(MAKE) -C $(PART_ONE) qt_build
	$(MAKE) -C $(PART_TWO) qt_build
	@echo "\nall build generated"

# Delete all from all parts - (part 2 and 3 not finish)
clean:
	${MAKE} -C $(PART_ONE) clean
	${MAKE} -C $(PART_TWO) clean
	@rm -rfv PARTIE_3/build/*
	@echo "\nall clean completed"

# Delete all generated directories and their components from all parts - (part 2 and 3 not finish)
clean_project:
	$(MAKE) -C $(PART_ONE) clean_project
	$(MAKE) -C $(PART_TWO) clean_project
	@echo "\nall clean project completed"

# Delete all Qt build from all parts - (part 2 and 3 not finish)
clean_qt_build:
	$(MAKE) -C $(PART_ONE) clean_qt_build
	$(MAKE) -C $(PART_TWO) clean_qt_build
	@echo "\nall clean build completed"
