CREATE TABLE IF NOT EXISTS students (
  id SERIAL PRIMARY KEY,
  student_no VARCHAR(20) UNIQUE NOT NULL,
  name VARCHAR(50),
  surname VARCHAR(50),
  department VARCHAR(50),
  email VARCHAR(100)
);

INSERT INTO students (student_no, name, surname, department, email)
VALUES ('220304017', 'Emirhan', 'Tekin', 'Computer Engineering', 'emirhan.tekin@stu.fbu.edu.tr')
ON CONFLICT (student_no) DO NOTHING;
