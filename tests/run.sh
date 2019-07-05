#test1
if [ "$1" = "1" ]; then
	echo 1024 3 2  > system.in
	./myOS simulator ./tests/test1.txt
	if cat system.out | tr '\n' ' ' | grep -q "Job #1 completed Deallocating 120 Memory at 744 Starting job #5 Allocating 20 Memory at 724 Job #2 completed Deallocating 10 Memory at 734 Starting job #6 Allocating 30 Memory at 704"; then echo "Test 1 Succeeded" >> report.txt; else echo "Test 1 Failed" >> report.txt; fi
	rm system.in

elif [ "$1" = "2" ]; then
	echo 1024 3 2 > system.in
	./myOS simulator ./tests/test2.txt
	if cat system.out | tr '\n' ' ' | grep -q "Job #6 completed Deallocating 30 Memory at 734 Starting job #2 Allocating 10 Memory at 724 Job #5 completed Deallocating 20 Memory at 744 Starting job #1 Allocating 120 Memory at 624"; then echo "Test 2 Succeeded" >> report.txt; else echo "Test 2 Failed" >> report.txt; fi
	rm system.in

fi

cat report.txt
