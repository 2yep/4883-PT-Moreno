message: str = input()
case: int = 0

while message != "*":
    case += 1
    if message[0] == "H":
        print(f"Case {case}: Hajj-e-Akbar")
    else:
        print(f"Case {case}: Hajj-e-Asghar")
    message = input()