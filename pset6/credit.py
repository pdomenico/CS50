def main():
    number = input("Number: ")
    first_sum = ""
    second_sum = 0
    print("First sum: ", end = "")
    for i in range(2, len(number)+1, 2):
        first_sum += str(int(number[-i])*2)
        print(number[-i], end="")
    
    print("\nSecond sum: ", end="")
    for i in range(1, len(number)+1, 2):
        second_sum += int(number[-i])
        print(number[-i], end="")
    print()

    first_final_sum = 0
    for n in first_sum:
        first_final_sum += int(n)

    print(f"Total: {first_sum} and {second_sum}")

    if (first_final_sum + second_sum)%10 != 0:
        print("INVALID NUMBER!")
        return
    
    match number[0]:
        case "3":
            print("AMEX")
            return
        case "4":
            print("VISA")
            return
        case "5":
            print("MASTERCARD")
            return
    print("COULD NOT RECOGNIZE NUMBER!")


if __name__ == "__main__":
    main()
