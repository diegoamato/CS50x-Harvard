from cs50 import get_string

# =============================================
# Implements the main function


def main():
    if check_validity(number):
        card = check_brand(number)
        print(f"{card}")
    else:
        print("INVALID")


# =============================================
# Ask a credit card number
number = get_string("Number: ")
while (len(number) < 1):
    number = get_int("Number: ")


# =============================================
# Implements the Luhn's Algorithm
def luhn_algorithm(number):

    # Adding and multiplying the card digits by 2
    check_sum = 0
    new_number = int(number)

    for i in range(len(number)):
        if i % 2 == 0:
            check_sum += (new_number % 10)
        elif i % 2 > 0:
            if ((new_number % 10) * 2) > 9:
                num = (new_number % 10) * 2
                check_sum += (num % 10) + 1
            elif ((new_number % 10) * 2) < 10:
                check_sum += (new_number % 10) * 2
        new_number //= 10

    # Validating if the last digit of the check_sum is 0
    if check_sum % 10 == 0:
        return True
    else:
        return False


# =============================================
# Check the validity of the credit card
def check_validity(number):
    if len(number) == 13 or len(number) == 15 or len(number) == 16:
        if luhn_algorithm(number):
            return True
    else:
        return False


# =============================================
# Check credit card brand
def check_brand(number):
    if len(number) == 15:
        if int(number) // 10**13 == 34 or int(number) // 10**13 == 37:
            card = "AMEX"
        else:
            card = "NOT FOUND BRAND"
    elif len(number) == 13:
        if int(number) // 10**12 == 4:
            card = "VISA"
        else:
            card = "NOT FOUND BRAND"
    elif len(number) == 16:
        if int(number) // 10**15 == 4:
            card = "VISA"
        elif (int(number) // 10**14) > 50 and (int(number) // 10**14) < 56:
            card = "MASTERCARD"
        else:
            card = "NOT FOUND BRAND"

    return card


# =============================================
# Call the main function
main()