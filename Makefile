run1:first
	g++ -std=c++11 first.cpp -o first && ./first
run2:second
	g++ -w -std=c++11 second.cpp -o second && strip second && upx -qqq second && ./second