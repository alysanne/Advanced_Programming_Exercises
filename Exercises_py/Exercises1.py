if __name__ == "__main__":
    DAYS_IN_YEAR = 365

    name = input("What's your name?: ")
    age = int(input("What's your age?: "))
    print(f"Hello {name}, you are {age} years old.")

    age_in_days = age * DAYS_IN_YEAR
    print(f"You are {age_in_days} days old.")
    
    pAge = age
    age = 10
    print(f"Memory address for 'age': {id(age)}, with value: {age}")
    print(f"Memory address for 'pAge': {id(pAge)}, with value: {pAge}")