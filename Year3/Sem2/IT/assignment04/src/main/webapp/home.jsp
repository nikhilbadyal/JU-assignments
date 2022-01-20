<%--suppress ALL --%>
<%@ page contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" %>



<%@ page import="java.sql.ResultSet" %>
<%@ page import="java.sql.Statement" %>
<%@ page import="java.sql.Connection" %>
<%@ page import="com.nikhil.assignment04.model.User" %>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Apparel Store</title>

    <link rel="stylesheet" href="css/home.css">
    <link rel="shortcut icon" href="images/store-logo.png">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</head>

<%
    if (request.getSession().getAttribute("user") == null) {
        response.sendRedirect("login_register.jsp");
        return;
    }
%>


<body>

<% response.setHeader("Cache-Control", "no-cache no-store must-revalidate");
    response.setHeader("Pragma", "no-cache");
    response.setHeader("Expires", "0");

%>

<!-- Navigation Menu -->
<nav class="navbar navbar-light">

    <div class="navigation">
        <!--logo------------>
        <a class="logo" href="https://pngimage.net/garments-logo-png-8/"><img
                src="https://pngimage.net/wp-content/uploads/2018/06/garments-logo-png-8.png" alt="garments logo png 8"></a>
        <p class="logo-text">Apparel Store</p>
        <!--menu-icon------------->

        <!--menu----------------->
        <ul class="menu">

            <li><a href="home.jsp">Home</a></li>
            <li class="shop"><a href="#"></a></li>
            <li><a href="product.jsp">Product</a>
                <!--lable---->
                <span class="sale-lable">New</span>
            </li>

        </ul>
        <!--right-menu----------->
        <div class="right-menu">
            <a href="javascript:void(0);" class="search">
                <i class="fa fa-search"></i>
            </a>
            <a href="#">
                <i class="fa fa-shopping-basket">
                    <span class="num-cart-product">0</span>
                </i>
            </a>

            <a href="Logout" class="user">
                <i class="fa fa-user"></i>
            </a>

        </div>
    </div>
</nav>

<!--search-bar----------------------------------->
<div class="search-bar">

    <!--search-input------->
    <div class="search-input">
        <input type="text" placeholder="Search For Product" name="search" id="search_input" autocomplete="off"/>
        <!--cancel-btn--->
        <a href="javascript:void(0);" class="search-cancel">
            <i class="fa fa-times"></i>
        </a>

    </div>
</div>


<!-- Slider -->

<!-----------full-slider----------------------------->
<div id="myCarousel" class="carousel slide" data-ride="carousel">
    <!-- Indicators -->
    <ol class="carousel-indicators">
        <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
        <li data-target="#myCarousel" data-slide-to="1"></li>
        <li data-target="#myCarousel" data-slide-to="2"></li>
    </ol>

    <!-- Wrapper for slides -->
    <div class="carousel-inner">

        <div class="item active">
            <img src="images/men_suit.jpg">
            <div class="carousel-caption">


                <span>Hi! <%=((User) (request.getSession().getAttribute("user"))).getFname()%>,<br> Welcome to the Apparel Store</span>
                <%--                <span>Hi! <br> Stranger,Welcome to the Apparel Store</span>--%>
                <strong>Let's shop online<br/> to <font>Save Money</font></strong>
                <a href="#" class="carousel-btn">Connect me</a>

            </div>
        </div>


        <div class="item">
            <img src="images/Slider_01.jpg">
            <div class="carousel-caption">

                <span>Limited Offer</span>
                <strong>50% Off<br/> With <font>Promo Code</font></strong>
                <a href="#" class="carousel-btn">Shop Now</a>

            </div>
        </div>

        <div class="item">
            <img src="images/Slider_02.jpg">
            <div class="carousel-caption">

                <span>Limited Offer</span>
                <strong>40% Off<br/> With <font>Promo Code</font></strong>
                <a href="#" class="carousel-btn">Shop Now</a>

            </div>
        </div>

        <div class="item">
            <img src="images/Slider_03.jpg">
            <div class="carousel-caption">

                <span>Limited Offer</span>
                <strong>40% Off<br/> With <font>Promo Code</font></strong>
                <a href="#" class="carousel-btn">Shop Now</a>

            </div>
        </div>


    </div>

    <!-- Left and right controls -->
    <a class="left carousel-control" href="#myCarousel" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left"></span>
        <span class="sr-only">Previous</span>
    </a>
    <a class="right carousel-control" href="#myCarousel" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right"></span>
        <span class="sr-only">Next</span>
    </a>
</div>

<!--NEW ARRIVAL OR 	DISCOUNTS PREFERENCE-------------------------------->
<section class="new-arrival">
    <span><i class="shopping-cart"></i></span>
    <!--heading-------->
    <div class="arrival-heading">
        <%
            if (((User) (request.getSession().getAttribute("user"))).getPrefer().equals("new")) { %>
        <strong>New Arrival</strong>
        <p>We Provide You New Fashion Design Clothes</p>
        <%
        } else if (((User) (request.getSession().getAttribute("user"))).getPrefer().equals("discounts")) {
        %>
        <strong>Discounts</strong>
        <p>We Provide You Discount Clothes</p>

        <%
            }
            ResultSet rs;
            Statement stat;
            Connection conn = (Connection) request.getServletContext().getAttribute("DBConnection");

            stat = conn.createStatement();
            String gender = ((User) (request.getSession().getAttribute("user"))).getGender();
            String prefer = ((User) (request.getSession().getAttribute("user"))).getPrefer();

            System.out.print(gender + " " + prefer);
            String sql = "select * from app_store.clothesData where gender='" + gender + "' and prefer='" + prefer + "'";
            rs = stat.executeQuery(sql);
            if (rs.next()) {
                do {
        %>

    </div>
    <!--products----------------------->
    <div class="product-container">
        <!--product-box-1---------->
        <div class="product-box">
            <!--product-img------------>
            <div class="product-img">
                <!--add-cart---->
                <a href="#" class="add-cart">
                    <i class="fa fa-shopping-cart"></i>
                </a>
                <!--img------>
                <% if (gender.equals("men")) { %>
                <img src="images/men/<%=rs.getString("image")%>">
                <%} else { %>
                <img src="images/women/<%=rs.getString("image")%>">
                <%} %>
                <!-- <img src="images/p-1.png">
-->                      </div>
            <!--product-details-------->
            <div class="product-details">
                <a href="#" class="p-name"><%=rs.getString("ctype")%>
                </a>
                <%-- <span class="p-price"><i class="fa fa-rupee"></i><%=rs.getString("price")%></span> --%>

                <a href="#" class="p-name">Dress</a>
                <span class="p-price"><i class="fa fa-rupee"></i><%=rs.getString("price")%></span>
                <!-- <span class="p-price"><i class="fa fa-rupee"></i>1200</span> -->
            </div>
        </div>


    </div>
    <%
        } while (rs.next());
    } else {

    %>
    <h3 class="text-danger center">Sorry for disappointing you... ! &#128546; </h3>
    <h3>We are not offering for your preference...</h3>
    <%} %>


</section>

<script
        src="https://code.jquery.com/jquery-3.5.1.js"
        integrity="sha256-QWo7LDvxbWT2tbbQ97B53yJnYU3WhH/C8ycbRAkjPDc="
        crossorigin="anonymous"></script>

<script>
    /*-----For Search Bar-----------------------------*/
    $(document).on('click', '.search', function () {
        $('.search-bar').addClass('search-bar-active')
    });

    $(document).on('click', '.search-cancel', function () {
        $('.search-bar').removeClass('search-bar-active')
    });


</script>

<script>
    $(document).ready(function () {

        var counts = 0;
        $(".add-cart").click(function () {

            counts += +1;
            $(".num-cart-product").animate({

                opacity: 1
            }, 300, function () {

                $(this).text(counts);
            });
        });
    });

</script>


</body>

<section class="footer">
    <!--copyright-------------->
    <span class="copyright">
         © 2021 Nikhil
    </span>
    <div class="subscribe">
        Made with L<i class="fa fa-heart"></i>VE
    </div>
</section>
</html>