def main():
    ticket_total = int(input("How many tickets: "))
    random_number = int(input("Random Number: "))

    winning_ticket = random_number % ticket_total

    print(f"Winning Ticket: {winning_ticket}")


if __name__ == "__main__":
    main()
