int main() {
    int x = 5;
    int* ptr1 = &x; // ptr1 points to x
    int* ptr2 = ptr1; // ptr2 is an alias for ptr1

    return 0;
}
