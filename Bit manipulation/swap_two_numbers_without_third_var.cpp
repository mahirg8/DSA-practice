void swapNumber(int &a, int &b) {
	// Write your code here.
	a = a + b; // Step 1: a becomes the sum of a and b
    b = a - b; // Step 2: b becomes the original value of a
    a = a - b; // Step 3: a becomes the original value of b
}