# Bus Booking System

A bus booking system developed in C that allows users to create accounts, log in, book tickets, and cancel tickets.

## Overview

This project is a console-based application that simulates a bus ticket booking system. Users can create accounts, log in, book bus tickets for specific dates and destinations, view their booked tickets, and cancel tickets if needed. The system also includes basic functionalities for admin users.

## Features

- **Account Management**: Users can create new accounts and log in using their credentials.
- **Booking Tickets**: Users can book bus tickets by entering travel details such as date, location, and destination.
- **Cancel Tickets**: Users can view and cancel their booked tickets.
- **Bus Status**: Displays the status of booked buses including bus class, seat number, and arrival status.
- **Admin Functionality**: Admin users can perform additional management tasks (to be implemented).

## How to Use

### Creating a New Account

1. Run the program.
2. Choose the option to create a new account.
3. Enter a unique username and a password.
4. Select the user type (0 for user, 1 for admin).
5. The account will be created if the username is available.

### Logging In

1. Run the program.
2. Choose the option to log in.
3. Enter your username and password.
4. If the credentials are correct, you will be logged in.

### Booking Tickets

1. Log in to your account.
2. Choose the option to book tickets.
3. Enter the month and date for your travel.
4. Enter your location and destination.
5. Confirm the booking if the details are correct.
6. The booking will be saved, and you will see other available buses and details.

### Canceling Tickets

1. Log in to your account.
2. Choose the option to cancel tickets.
3. View your booked buses.
4. Enter the bus number you want to cancel.
5. Confirm the cancellation.
6. The ticket will be canceled and removed from your booked buses.

### Viewing Bus Status

1. Log in to your account.
2. Choose the option to view bus status.
3. View the details of your booked buses including bus class, seat number, and arrival status.

## Project Structure

- **User Management**: Functions to create accounts, log in, and manage user information.
- **Bus Management**: Functions to book and cancel bus tickets, and display bus status.
- **Data Structures**: Linked lists to store user information and booked buses.


## Getting Started

1. Clone the repository:

   ```bash
   git clone https://github.com/SubhodeepSamanta/Bus-Reservation-System.git

## License
This project is licensed under the MIT License. 
