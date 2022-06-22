import sys, csv

def main():
    # Check if CLA have been provided
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} database sequence")
        return

    samples = []
    database = {}

    # Open the database
    with open(sys.argv[1], 'r') as database_file:
        database_reader = csv.reader(database_file)
        for element in database_reader.__next__():
            # Create a list of the bases sequences
            if element == "name":
                continue
            samples.append(element)
        
        # Read the rest of the lines
        for row in database_reader:
            # For every person, create a dict with sequence as keys and number of repetitions as values
            repetitions_dict = dict()
            for i in range(len(samples)):
                repetitions_dict[samples[i]] = row[i+1]

            # Assign the sequence dictonary to each name
            database[row[0]] = repetitions_dict
        
    # Open the sequence
    with open(sys.argv[2], 'r') as sequence_file:
        sequence = sequence_file.read()

    
    # For every sequence sample, iterate through the list and memorize how many times it repeats
    sequence_repetitions = dict()
    for sample in samples:
        #print(f"Currently checking for {sample}")
        #print(f"The sequence is {sequence}")
        sequence_repetitions[sample] = 0
        flow = False
        temp = 0
        i = 0
        while i < (len(sequence) - len(sample)):
            #print(f"Checking {sequence[i:i+len(sample)]} against {sample}")
            if sequence[i:i+len(sample)] == sample:
                #print(f"{sequence[i:i+len(sample)]} matches with the sample")
                i += len(sample)
                if flow:
                    temp += 1
                else:
                    flow = True
                    temp = 1
                #print(temp)
            else:
                flow = False
                if temp > sequence_repetitions[sample]:
                    sequence_repetitions[sample] = temp
                temp = 0
                i += 1

    # test prints
    print(f"Fred profile: {database['Fred']}")
    print(f"Found: {sequence_repetitions}")


    # Iterate through the database, if any match is found, print it
    for key in database:
        match = True
        for sample in database[key]:
            if int(database[key][sample]) != sequence_repetitions[sample]:
                if key == 'Fred':
                    print(f"{database[key][sample]} does not equal {sequence_repetitions[sample]}")
                match = False
                break
        if match:
            print(f"MATCH FOUND: {key}")
            return
    print("No match") 





if __name__ == "__main__":
    main()
