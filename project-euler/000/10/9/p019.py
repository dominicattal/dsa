def solve():
    # jan 1, 1901 was tuesday
    day_name = 3  # 1 sunday, 7 sat
    month_day = 1
    month = 1  # jan to dec
    year = 1901
    num_sundays = 0

    while year != 2001:

        if day_name == 1 and month_day == 1:
            num_sundays += 1

        if day_name < 7:
            day_name += 1
        elif day_name == 7:
            day_name = 1

        if month == 9 or month == 4 or month == 11 or month == 6:
            if month_day < 30:
                month_day += 1
            else:
                month_day = 1
                month += 1
        elif month == 2 and year % 4 == 0:
            if month_day < 29:
                month_day += 1
            else:
                month_day = 1
                month += 1
        elif month == 2 and year % 4 != 0:
            if month_day < 28:
                month_day += 1
            else:
                month_day = 1
                month += 1
        else:
            if month_day < 31:
                month_day += 1
            else:
                month_day = 1
                month += 1

        if month == 13:
            month = 1
            year += 1

    print(num_sundays)

solve()