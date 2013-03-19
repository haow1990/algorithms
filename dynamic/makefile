ALL = longest_increasing_subsequence knapsack01 edit_distance

longest_increasing_subsequence: longest_increasing_subsequence.c
	gcc -o longest_increasing_subsequence -g longest_increasing_subsequence.c

knapsack01: knapsack01.c
	gcc -o knapsack01 -g knapsack01.c

edit_distance: edit_distance.cc edit_distance_test.cc
	g++ -o edit_distance -g edit_distance.cc edit_distance_test.cc

clean:
	rm -f ${ALL}
