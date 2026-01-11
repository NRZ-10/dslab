<?php
$conn = new mysqli("localhost", "root", "", "programdb");
if ($conn->connect_error) die("Connection failed");

if (!empty($_POST['submit'])) {
    $id   = $_POST['emp_id'];
    $name = $_POST['emp_name'];
    $des  = $_POST['designation'];
    $sal  = $_POST['salary'];

    $conn->query("INSERT INTO employee_details (emp_id, emp_name, designation, salary)
                  VALUES ('$id', '$name', '$des', '$sal')");
}
?>
<!DOCTYPE html>
<html>
<head><title>Employee Information</title></head>
<body>

<h2 align="center">EMPLOYEE INFORMATION</h2>

<form method="post">
<table border="1" align="center" cellpadding="5">
<tr>
    <td>Employee ID:</td>
    <td><input type="number" name="emp_id" required></td>
</tr>
<tr>
    <td>Employee Name:</td>
    <td><input type="text" name="emp_name" required></td>
</tr>
<tr>
    <td>Designation:</td>
    <td><input type="text" name="designation" required></td>
</tr>
<tr>
    <td>Salary:</td>
    <td><input type="number" name="salary" required></td>
</tr>
<tr>
    <td colspan="2" align="center">
        <input type="submit" name="submit" value="Add Employee">
    </td>
</tr>
</table>
</form>

<br><hr><br>

<h3 align="center">All Employee Details</h3>

<table border="1" align="center" cellpadding="5">
<tr style="background-color:lightgray;">
    <th>Employee ID</th>
    <th>Name</th>
    <th>Designation</th>
    <th>Salary</th>
</tr>

<?php
$result = $conn->query("SELECT * FROM employee_details");

if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>{$row['emp_id']}</td>
                <td>{$row['emp_name']}</td>
                <td>{$row['designation']}</td>
                <td>{$row['salary']}</td>
              </tr>";
    }
} else {
    echo "<tr><td colspan='4' align='center'>No employees found</td></tr>";
}

$conn->close();
?>
</table>

</body>
</html>