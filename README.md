 try 😁😁

**Here are the Oracle SQL and PL/SQL commands to solve the given problems:**

**1. SQL Queries on Employee Table:**

```sql
i) SELECT emp_id FROM Employee WHERE emp_city IN ('Pune', 'Nagpur');
ii) UPDATE Employee SET emp_name = 'Ayan' WHERE emp_name = 'Ayush';
iii) SELECT COUNT(*) FROM Employee WHERE emp_dept = 50;
```

**2. Creating a View:**

```sql
CREATE VIEW HighBalanceView AS
SELECT ACC_No, PAN FROM Depositor WHERE Balance > 100000;
```

**3. Creating a Sequence:**

```sql
CREATE SEQUENCE Seq_1
START WITH 1
INCREMENT BY 1
MINVALUE 1
MAXVALUE 20;
```

**4. PL/SQL Program for Divide by Zero Exception:**

```sql
DECLARE
  num1 NUMBER := 10;
  num2 NUMBER := 0;
  result NUMBER;
BEGIN
  result := num1 / num2;
  DBMS_OUTPUT.PUT_LINE('Result: ' || result);
EXCEPTION
  WHEN ZERO_DIVIDE THEN
    DBMS_OUTPUT.PUT_LINE('Error: Division by zero');
END;
/
```

**5. User Management:**

```sql
i) CREATE USER Rahul IDENTIFIED BY password;
ii) GRANT CREATE SESSION, SELECT, INSERT, UPDATE, DELETE, DROP TO Rahul;
iii) REVOKE SELECT ON Employee FROM Rahul;
```

**6. Creating Synonyms:**

```sql
CREATE SYNONYM Emp_Alias FOR Employee;
```

**7. Aggregate Functions:**

```sql
SELECT COUNT(*), SUM(salary), AVG(salary), MIN(salary), MAX(salary)
FROM Employee;
```

**8. Implicit Cursor:**

```sql
DECLARE
  emp_rec Employee%ROWTYPE;
BEGIN
  SELECT * INTO emp_rec FROM Employee WHERE emp_id = 101;
  DBMS_OUTPUT.PUT_LINE(emp_rec.emp_name);
END;
/
```

**9. Explicit Cursor:**

```sql
DECLARE
  CURSOR emp_cur IS SELECT * FROM Employee;
  emp_rec Employee%ROWTYPE;
BEGIN
  OPEN emp_cur;
  LOOP
    FETCH emp_cur INTO emp_rec;
    EXIT WHEN emp_cur%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE(emp_rec.emp_name);
  END LOOP;
  CLOSE emp_cur;
END;
/
```

**10. Creating a Table and Inserting Data:**

```sql
CREATE TABLE Student (
  RNO NUMBER PRIMARY KEY,
  name VARCHAR2(50),
  marks NUMBER,
  dept VARCHAR2(50)
);

INSERT INTO Student VALUES (1, 'Alice', 90, 'CS');
-- Insert other 4 records similarly
```

**11. Factorial Calculation:**

```sql
DECLARE
  num NUMBER := 5;
  factorial NUMBER := 1;
BEGIN
  FOR i IN 1..num LOOP
    factorial := factorial * i;
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('Factorial of ' || num || ' is ' || factorial);
END;
/
```

**12. Creating and Dropping Indexes:**

```sql
CREATE INDEX emp_name_idx ON Employee(emp_name);
DROP INDEX emp_name_idx;
```

**13. Reversing a Number:**

```sql
DECLARE
  num NUMBER := 1234;
  reverse_num NUMBER := 0;
  digit NUMBER;
BEGIN
  WHILE num > 0 LOOP
    digit := MOD(num, 10);
    reverse_num := reverse_num * 10 + digit;
    num := TRUNC(num / 10);
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('Reverse number: ' || reverse_num);
END;
/
```

**14. SQL Queries on EMP Table:**

```sql
i) SELECT * FROM Emp;
ii) SELECT ename FROM Emp WHERE city = 'Mumbai';
iii) UPDATE Emp SET salary = 50000 WHERE ename = 'Ramesh';
iv) SELECT ename FROM Emp WHERE salary < 50000;
```

**15. SQL Queries on Customer Table:**

```sql
i) SELECT * FROM Customer;
ii) SELECT name FROM Customer WHERE balance = 10000;
iii) UPDATE Customer SET city = 'Mumbai' WHERE name = 'Ramesh' AND city = 'Pune';
```**16. Finding the Greater Number Using IF Statement:**

```sql
DECLARE
  num1 NUMBER := 20;
  num2 NUMBER := 15;
BEGIN
  IF num1 > num2 THEN
    DBMS_OUTPUT.PUT_LINE(num1 || ' is greater than ' || num2);
  ELSIF num2 > num1 THEN
    DBMS_OUTPUT.PUT_LINE(num2 || ' is greater than ' || num1);
  ELSE
    DBMS_OUTPUT.PUT_LINE('Both numbers are equal');
  END IF;
END;
/
```

**17. Pass or Fail Using IF-THEN-ELSE:**

```sql
DECLARE
  marks NUMBER := 60;
BEGIN
  IF marks >= 40 THEN
    DBMS_OUTPUT.PUT_LINE('Pass');
  ELSE
    DBMS_OUTPUT.PUT_LINE('Fail');
  END IF;
END;
/
```

**18. Finding Grade Using Nested IF-THEN-ELSE:**

```sql
DECLARE
  marks NUMBER := 85;
BEGIN
  IF marks >= 90 THEN
    DBMS_OUTPUT.PUT_LINE('A');
  ELSIF marks >= 80 THEN
    DBMS_OUTPUT.PUT_LINE('B');
  ELSIF marks >= 70 THEN
    DBMS_OUTPUT.PUT_LINE('C');
  ELSE
    DBMS_OUTPUT.PUT_LINE('Fail');
  END IF;
END;
/
```

**19. Finding Grade Using CASE Statement:**

```sql
DECLARE
  marks NUMBER := 75;
BEGIN
  CASE
    WHEN marks >= 90 THEN
      DBMS_OUTPUT.PUT_LINE('A');
    WHEN marks >= 80 THEN
      DBMS_OUTPUT.PUT_LINE('B');
    WHEN marks >= 70 THEN
      DBMS_OUTPUT.PUT_LINE('C');
    ELSE
      DBMS_OUTPUT.PUT_LINE('Fail');
  END CASE;
END;
/
```

**20. Printing Table of 5 Using Simple Loop:**

```sql
DECLARE
  num NUMBER := 5;
  i NUMBER;
BEGIN
  FOR i IN 1..10 LOOP
    DBMS_OUTPUT.PUT_LINE(num * i);
  END LOOP;
END;
/
```

**21. Printing Table of 10 Using While Loop:**

```sql
DECLARE
  num NUMBER := 10;
  i NUMBER := 1;
BEGIN
  WHILE i <= 10 LOOP
    DBMS_OUTPUT.PUT_LINE(num * i);
    i := i + 1;
  END LOOP;
END;
/
```

**22. Printing Numbers from 10 to 1 Using Reverse FOR Loop:**

```sql
DECLARE
  i NUMBER;
BEGIN
  FOR i IN REVERSE 10..1 LOOP
    DBMS_OUTPUT.PUT_LINE(i);
  END LOOP;
END;
/
```

**23. Same as 22.**

**24. Checking Even or Odd:**

```sql
DECLARE
  num NUMBER := 12;
BEGIN
  IF MOD(num, 2) = 0 THEN
    DBMS_OUTPUT.PUT_LINE(num || ' is even');
  ELSE
    DBMS_OUTPUT.PUT_LINE(num || ' is odd');
  END IF;
END;
/
```

**25. Calculating Sum Using a Function:**

```sql
CREATE OR REPLACE FUNCTION calculate_sum(p_num1 IN NUMBER, p_num2 IN NUMBER)
RETURN NUMBER
IS
  v_sum NUMBER;
BEGIN
  v_sum := p_num1 + p_num2;
  RETURN v_sum;
END;
/

DECLARE
  num1 NUMBER := 10;
  num2 NUMBER := 20;
  result NUMBER;
BEGIN
  result := calculate_sum(num1, num2);
  DBMS_OUTPUT.PUT_LINE('Sum: ' || result);
END;
/
```