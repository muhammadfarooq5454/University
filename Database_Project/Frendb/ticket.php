<!DOCTYPE html>
<html>
<head>
  <title></title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
  <?php include 'header.php'; ?>
 <div class="row">
<?php
$con=mysqli_connect('localhost','root');
mysqli_select_db($con,'frendb');
//if($con)
//{
//echo "Connection successful";
//}
//else
//{
 // echo "Connection failed";
//}

$querry ="SELECT * FROM `ticket` order by ticketid ASC";
$querryfire=mysqli_query($con,$querry);
$num=mysqli_num_rows($querryfire);
if($num>0)
{
  while($tkt=mysqli_fetch_array($querryfire))
  {
    ?>
      <div class="col-lg-3 col-med-3 col-sm-12">

        <form>
          <div class="card">
            <h6 class="card title bg-info text-white p-2 text-uppercase "><?php echo $tkt['Route'];
            ?></h6>

            <div class="card body">
             <img src="<?php echo $tkt['image']; ?> " alt="ticket" class="img-fluid mb-2">

              <h6> &#8360; <?php echo $tkt['price']; ?><span>(<?php echo $tkt['date'];  ?>) </span></h6>

              <h6 class="badge badge-success">4.4<i class="fa fa-star"></i></h6>       
            </div>
          <!--<input type="text" name="" class="form-control" placeholder="Quantity">-->
            <div class="btn-group d-flex">
              <a href="addtickettocart.php?id=<?php echo $tkt['ticketid']; ?>" class="btn btn-success flex-fill">Book Ticket</a>
              
            </div>
          </div>
        </form>


      </div>


    <?php
  }
}


?>
</body>
</html>