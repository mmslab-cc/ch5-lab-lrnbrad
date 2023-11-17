lab1.out:
	gcc ch5-lab1/source/*

lab1: lab1.out
	bash lab1.sh

lab2.out:
	gcc ch5-lab2/source/*

lab2: lab2.out
	bash lab2.sh

convert:
	dos2unix *.sh