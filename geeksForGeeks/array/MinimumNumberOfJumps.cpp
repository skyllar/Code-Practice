int calculate_min_jumps(int arr[], int n) {
		
	int global_last_reachable_index = 0;
	int total_min_steps_required = 0;
	
	for(int i = 0; i < n; i++) {
		
		// No point in continuing as the global last reachable index is even less than this!
		if (global_last_reachable_index < i) {
			break;
		}
		
		int cur_last_reachable_index = i + arr[i];
		
		if (cur_last_reachable_index > global_last_reachable_index) {
			// Be always greedy for those who can take you farther... :blush:
			global_last_reachable_index = cur_last_reachable_index;
			total_min_steps_required ++; 
		} 
		
		if (global_last_reachable_index >= n - 1) {
			cout << "Breaking when global_last_reachable_index: " << global_last_reachable_index <<\
			 ", global_last_reachable_index: " << global_last_reachable_index <<\
			 ", cur_last_reachable_index: " << cur_last_reachable_index << "\n";
			break;
		}
	}
		
	if (global_last_reachable_index < n - 1)
		return -1;
	else
		return total_min_steps_required;
	
}
