# 🎓 GPA Calculator (Python CLI Tool)

This is a simple Python command-line tool for calculating your GPA based on course grades and credit hours.

---

## 📌 Features

- Accepts multiple course GPA inputs along with their credit hours
- Validates GPA input (must be between 0.0 and 4.0)
- Calculates and displays the weighted average GPA
- Simple command-line interface for quick use

---

## 🧠 How It Works

1. The user is prompted to input the **GPA for a course**.
2. If the input is valid (between 0 and 4), the user is then prompted to enter **credit hours** for that course.
3. The user repeats this for all courses.
4. When done, the user enters `5` to trigger the GPA calculation.
5. The script calculates the **weighted GPA** using the formula:

\[
\text{GPA} = \frac{\sum (\text{GPA} \times \text{Credit Hours})}{\sum \text{Credit Hours}}
\]

---

## 🚀 How to Run

Make sure you have Python installed. Then run:

```bash
python gpa_calc.py
```

---

## 🧪 Sample Interaction

```
Enter course GPA (or 5 to calculate GPA with entered data): 3.7
Enter course hours: 3
Enter course GPA (or 5 to calculate GPA with entered data): 4.0
Enter course hours: 4
Enter course GPA (or 5 to calculate GPA with entered data): 5
Your GPA is: 3.87
```

---

## 📜 License

This project is open-source and free to use for educational or personal use.
