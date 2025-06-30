
inp = 0.0
gpa = 0.0
mid_calc = 0.0
hours = 0.0
total_hours = 0.0

while True:

    inp = float(input('Enter course GPA (or 5 to calculate GPA with entered data): '))

    if inp == 5:

        break

    if inp < 0 or inp > 5:

        print('Invalid input. Please enter a GPA between 0 and 4.')

        continue

    else:

        hours = float(input('Enter course hours: '))

        total_hours += hours

        mid_calc += inp * hours

gpa = mid_calc / total_hours

print (f'Your GPA is: {gpa:.2f}')