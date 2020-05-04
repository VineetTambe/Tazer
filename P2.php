<style>
table
{
	border-collapse:collapse;
}
td
{
	padding:10px;
	border:3px solid rgb(0,0,255);
}
th
{
	text-align: left;
	background-color: rgb(250,40,0);
	color:rgb(255,255,255);
}
table tr:nth-child(odd) td{
	background-color: rgb(10,150,210);
}	
</style>
<?php
$servername = "localhost";
$username = "username";
$password = "1234";
$dbname = "location_db";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
//echo "Connected";
//$conn->close();
error_reporting(0);
if($conn) mysqli_select_db($conn,$dbname);
$query="SELECT * FROM tracking_location";
$data=mysqli_query($conn ,$query);
$total=mysqli_num_rows($data);
//$result=mysqli_fetch_assoc($data);

if($total!=0)
{
	?>
	<table width="40%">
		<tr>
			<th width=30%>ID</th>
			<th width=30%>LATITUDE</th>
			<th width=30%>LONGITUDE</th>
			<th colspan="2">OPERATIONS</th>
		</tr>
	
	<?php
	while($result=mysqli_fetch_assoc($data))
	{
		//echo $result['ID']." ".$result['LATITUDE']." ".$result['LONGITUDE']."</br>";
		echo"<tr>
	<td>".$result['ID']."</td>
			<td>".$result['LATITUDE']."</td>
			<td>".$result['LONGITUDE']."</td>
			<td><a href='p3.php?id=$result[ID]&lat=$result[LATITUDE]&lon=$result[LONGITUDE]'>Edit</a></td>
			</tr>";
	}
}
else
{
	echo "No records to display for given query";
}
?>
</table>