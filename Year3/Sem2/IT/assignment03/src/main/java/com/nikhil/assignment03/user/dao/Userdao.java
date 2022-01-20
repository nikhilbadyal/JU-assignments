package com.nikhil.assignment03.user.dao;

import com.nikhil.assignment03.user.model.Customer;
import com.nikhil.assignment03.user.model.CustomerModelForLogin;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Userdao {
    private final Connection conn;

    public Userdao(Connection conn) {
        this.conn = conn;
    }

    public Customer get(CustomerModelForLogin customerModelForLogin) {
        Customer customer = null;

        String sql = "select * from traveldatabase.customer where username=? ";
        try {
            ResultSet res;
            PreparedStatement st = conn.prepareStatement(sql);
            st.setString(1, customerModelForLogin.getUsername());
            res = st.executeQuery();
            if (res.next()) {
                String email = res.getString("email");
                String phone = res.getString("phone");
                String address = res.getString("address");
                customer = new Customer(customerModelForLogin.getUsername(),
                        email, customerModelForLogin.getPassword(),
                        phone, address);
            }
        } catch (SQLException e) {
            e.printStackTrace();

        }
        return customer;

    }
}
