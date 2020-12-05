.PHONY : clean

# Delete all Qt build from all project parts
clean :
	@echo "----------PARTIE 1----------"
	${MAKE} -C PARTIE_1 clean
	@echo "----------PARTIE 2----------"
	@rm -rfv PARTIE_2/build/*
	@echo "----------PARTIE 3----------"
	@rm -rfv PARTIE_3/build/*
	@echo "\nall clean completed"