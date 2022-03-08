import csv
import sys


def main():

    # DONE: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    # DONE: Read database file into a variable
    test = []
    str_seq = []
    sqrdb = sys.argv[1]
    with open(sqrdb, "r") as file1:
        dbreader = csv.DictReader(file1)
        for person in dbreader:
            test.append(person)
        str_seq = dbreader.fieldnames[1:]

    # DONE: Read DNA sequence file into a variable
    dna = []
    dnasq = sys.argv[2]
    with open(dnasq, "r") as file2:
        dna = file2.read()

    # DONE: Find longest match of each STR in DNA sequence
    str_count = {}
    for STR in str_seq:
        x = longest_match(dna, STR)
        str_count[STR] = x

    # DONE: Check database for matching profiles
    count_test = 0
    for person in test:
        name = person['name']
        for STR in str_seq:
            if int(person[STR]) != str_count[STR]:
                count_test += 1
        if count_test == 0:
            print(name)
            exit(0)
        else:
            count_test = 0
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()