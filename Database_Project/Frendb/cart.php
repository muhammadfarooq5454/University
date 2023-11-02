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
    <h1>CART</h1>
 <div class="row">
<?php
include 'config.php';

session_start();

$querry ="SELECT * FROM cart c inner join product p on p.id = c.product_id where c.user_id = {$_SESSION['user_id']} order by id ASC";
$querryfire=mysqli_query($con,$querry);
$num=mysqli_num_rows($querryfire);
if($num>0)
{
  while($prdt=mysqli_fetch_array($querryfire))
  {
    ?>
      <div class="col-lg-3 col-med-3 col-sm-12">
          <div class="card">
            <h6 class="card title bg-info text-white p-2 text-uppercase "><?php echo $prdt['name'];
            ?></h6>

            <div class="card body">
             <img src="<?php echo $prdt['image']; ?> " alt="grocery" class="img-fluid mb-2">

              <h6> &#8360; <?php echo $prdt['price']; ?><span>(<?php echo $prdt['discount'];  ?>)% off </span></h6>

              <h6 class="badge badge-success">4.4<i class="fa fa-star"></i></h6>

            </div>
            <form action="changeQuantity.php" method="get">
              <p>Quantity</p>
              <input type="hidden" name='id' value="<?php echo $prdt['id'] ?>">
              <input type="number" name="quantity" class="form-control" value="<?php echo $prdt['cart_quantity'] ?>">
              <button type="submit" name="update">Update</button>
            </form>
          </div>

      </div>

    <?php
  }
}


?>

 <div class="btn-group d-flex">
              <a href="order.php" class="btn btn-success flex-fill">Buy Now</a></div>
</div>
</body>
</html>
