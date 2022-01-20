package com.nikhil.assignment03.user.dao;

import com.nikhil.assignment03.user.model.Customer;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class RegisterDao {
    private final Connection conn;

    public RegisterDao(Connection conn) {
        this.conn = conn;
    }


    public boolean insert(Customer customer) {


        boolean res = false;

        String sql = "insert into traveldatabase.customer values(?,?,?,?,?)";
        try {
            try (PreparedStatement st = conn.prepareStatement(sql)) {
                st.setString(1, customer.getUname());
                st.setString(2, customer.getEmail());
                st.setString(3, customer.getPassword());
                st.setString(4, customer.getPhone());
                st.setString(5, customer.getAddress());
                res = st.executeUpdate() > 0;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;

    }
}
