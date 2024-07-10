#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct BookedBus {
    int month;
    int date;
    char location[50];
    char destination[50];
    struct BookedBus* next;
} BookedBus;

typedef struct User {
    char username[50];
    char password[50];
    int type;
    int booked;
    BookedBus* bookedBuses;
    struct User* next;
} User;

typedef struct Bus {
    int month;
    int date;
    char location[50];
    char destination[50];
    struct Bus* next;
} Bus;

void displayMenu();
User* createUser(char username[], char password[], int type);
void addUser(User** head, char username[], char password[], int type);
int checkUsernameAvailability(User* head, char username[]);
User* loginUser(User* head, char username[], char password[]);
void displayBookedBuses(User* user);
void bookTickets(User* user, Bus** head);
void cancelTickets(User* user);

int main() {
    User* userList = NULL;
    Bus* busList = NULL;
    
    addUser(&userList, "subhodeep", "90909090", 1);
    addUser(&userList, "kashish", "90909090", 1);
    addUser(&userList, "test", "testadmin", 1);
    
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    char newUsername[50];
                    char newPassword[50];
                    int userType;
                    
                    printf("Enter a username: ");
                    scanf("%s", newUsername);
                    
                    if (checkUsernameAvailability(userList, newUsername) == 0) {
                        printf("Username already exists. Please choose a different username.\n");
                        break;
                    }
                    
                    printf("Enter a password: ");
                    scanf("%s", newPassword);
                    
                    printf("Enter user type (0 for user, 1 for admin): ");
                    scanf("%d", &userType);
                    
                    addUser(&userList, newUsername, newPassword, userType);
                    
                    printf("Account created successfully!\n");
                    break;
                }
            case 2:
                {
                    char enteredUsername[50];
                    char enteredPassword[50];
                    
                    printf("Enter username: ");
                    scanf("%s", enteredUsername);
                    
                    printf("Enter password: ");
                    scanf("%s", enteredPassword);
                    
                    User* loggedInUser = loginUser(userList, enteredUsername, enteredPassword);
                    
                    if (loggedInUser != NULL) {
                        printf("Logged in successfully as %s\n", loggedInUser->username);
                        
                        int userChoice;
                        do {
                            printf("\n===== Options =====\n");
                            printf("1. Book Tickets\n");
                            printf("2. Cancel Tickets\n");
                            printf("3. Bus Status\n");
                            printf("4. Logout\n");
                            printf("Enter your choice: ");
                            scanf("%d", &userChoice);
                            
                            switch(userChoice) {
                                case 1:
                                    bookTickets(loggedInUser, &busList);
                                    break;
                                case 2:
                                    cancelTickets(loggedInUser);
                                    break;
                                case 3:
                                    displayBookedBuses(loggedInUser);
                                    break;
                                case 4:
                                    printf("Logged out successfully.\n");
                                    break;
                                default:
                                    printf("Invalid choice. Please try again.\n");
                            }
                        } while(userChoice != 4);
                        
                    } else {
                        printf("Incorrect username or password.\n");
                    }
                    
                    break;
                }
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}

void displayBookedBuses(User* user) {
    if (user->bookedBuses == NULL) {
        printf("No buses booked.\n");
        return;
    }
    
    printf("\n===== Booked Buses =====\n");
    BookedBus* currentBus = user->bookedBuses;
    int busNumber = 1;
    
    while (currentBus != NULL) {
        printf(" \n Bus %d:\n", busNumber);
        printf("Date: %d/%d\n", currentBus->date, currentBus->month);
        printf("Location: %s\n", currentBus->location);
        printf("Destination: %s\n", currentBus->destination);
        
        char* busClasses[4] = {"Tier 1", "Tier 2", "Tier 3", "Tier 4"};
        int classIndex = rand() % 4;
        printf("Bus Class: %s\n", busClasses[classIndex]);
        
        int seatNumber = rand() % 50 + 1;
        printf("Seat Number: %d\n", seatNumber);
        
        printf("Status: ");
        if (rand() % 2 == 0) {
            printf("OnTime\n");
        } else {
            printf("Late\n");
            int lateBy = rand() % 12 + 1;
            printf("Late By: %d hours\n", lateBy);
        }
        
        int arrivingHour = rand() % 12 + 1;
        int arrivingMinutes = rand() % 2 == 0 ? 0 : 30;
        printf("Arriving in: %d:%02d %s\n", arrivingHour, arrivingMinutes, rand() % 2 == 0 ? "am" : "pm");
        
        printf("\n");
        
        currentBus = currentBus->next;
        busNumber++;
    }
}

void cancelTickets(User* user) {
    if (user->bookedBuses == NULL) {
        printf("No buses booked.\n");
        return;
    }
    
    printf("\n===== Cancel Tickets =====\n");
    BookedBus* currentBus = user->bookedBuses;
    int busNumber = 1;
    
    while (currentBus != NULL) {
        printf(" \n Bus %d:\n", busNumber);
        printf("Date: %d/%d\n", currentBus->date, currentBus->month);
        printf("Location: %s\n", currentBus->location);
        printf("Destination: %s\n", currentBus->destination);
        
        char* busClasses[4] = {"Tier 1", "Tier 2", "Tier 3", "Tier 4"};
        int classIndex = rand() % 4;
        printf("Bus Class: %s\n", busClasses[classIndex]);
        
        int seatNumber = rand() % 50 + 1;
        printf("Seat Number: %d\n", seatNumber);
        
        printf("Status: ");
        if (rand() % 2 == 0) {
            printf("OnTime\n");
        } else {
            printf("Late\n");
            int lateBy = rand() % 12 + 1;
            printf("Late By: %d hours\n", lateBy);
        }
        
        int arrivingHour = rand() % 12 + 1;
        int arrivingMinutes = rand() % 2 == 0 ? 0 : 30;
        printf("Arriving in: %d:%02d %s\n", arrivingHour, arrivingMinutes, rand() % 2 == 0 ? "am" : "pm");
        
        printf("\n");
        currentBus = currentBus->next;
        busNumber++;
    }
    
    printf("Enter the bus number you want to cancel: ");
    int cancelChoice;
    scanf("%d", &cancelChoice);
    
    currentBus = user->bookedBuses;
    BookedBus* previousBus = NULL;
    busNumber = 1;
    
    while (currentBus != NULL && busNumber < cancelChoice) {
        previousBus = currentBus;
        currentBus = currentBus->next;
        busNumber++;
    }
    
    if (currentBus == NULL) {
        printf("Invalid bus number.\n");
        return;
    }
    
    printf("Do you want to cancel Bus %d? (Yes/No): ", cancelChoice);
    char confirm[5];
    scanf("%s", confirm);
    
    if (strcmp(confirm, "Yes") == 0) {
        if (previousBus == NULL) {
            user->bookedBuses = currentBus->next;
        } else {
            previousBus->next = currentBus->next;
        }
        free(currentBus);
        printf("Bus %d cancelled.\n", cancelChoice);
    } else if (strcmp(confirm, "No") == 0) {
        printf("Booking cancellation failed.\n");
    } else {
        printf("Invalid choice. Booking cancellation failed.\n");
    }
}

void displayMenu() {
    printf("\n===== Welcome to WanderWheel =====\n");
    printf("1. Create a New Account\n");
    printf("2. Log In\n");
    printf("3. Exit\n");
}

User* createUser(char username[], char password[], int type) {
    User* newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->type = type;
    newUser->next = NULL;
    return newUser;
}

void addUser(User** head, char username[], char password[], int type) {
    User* newUser = createUser(username, password, type);
    newUser->next = *head;
    *head = newUser;
}

int checkUsernameAvailability(User* head, char username[]) {
    User* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->username, username) == 0) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

User* loginUser(User* head, char username[], char password[]) {
    User* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->username, username) == 0 && strcmp(temp->password, password) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void bookTickets(User* user, Bus** head) {
    int month, date;
    char location[50], destination[50];
    char confirm[5];
    char locations[9][50] = {"Kolkata", "Delhi", "Mumbai", "Bangalore", "Goa", "Hyderabad", "Noida", "Pune", "Chandigarh"};
    
    printf("===== Book Tickets =====\n");
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    
    if (month < 1 || month > 12) {
        printf("Invalid month. Please enter a month between 1 and 12.\n");
        return;
    }
    
    printf("Enter date of the month: ");
    scanf("%d", &date);
    
    if (date < 1 || ((month == 2 && date > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30) || (date > 31))) {
        printf("Invalid date for the given month. Please enter a valid date.\n");
        return;
    }
    
    printf("Enter your location: ");
    scanf("%s", location);
    
    printf("Enter your destination: ");
    scanf("%s", destination);
    srand(time(NULL));
    
    int availability = rand() % 99 + 1;
    int price = rand() % 4001 + 1000;
    
    printf("\n===== Best Option For You =====\n");
    printf("Date: %d/%d/2024\n", date, month);
    printf("Location: %s\n", location);
    printf("Destination: %s\n", destination);
    printf("Availability: %d%%\n", availability);
    printf("Price: $%d\n", price);
    printf("Do you want to Confirm? (Yes/No): ");
    scanf("%s", confirm);
    if (strcmp(confirm, "Yes") == 0) {
        printf("Booked successfully!\n");
        
        BookedBus* newBooking = (BookedBus*)malloc(sizeof(BookedBus));
        newBooking->month = month;
        newBooking->date = date;
        strcpy(newBooking->location, location);
        strcpy(newBooking->destination, destination);
        newBooking->next = NULL;
        
        if (user->bookedBuses == NULL) {
            user->bookedBuses = newBooking;
        } else {
            BookedBus* lastBooking = user->bookedBuses;
            while (lastBooking->next != NULL) {
                lastBooking = lastBooking->next;
            }
            lastBooking->next = newBooking;
        }
        
        printf("\n===== Other Buses By WanderBus =====\n");
        printf("Date: %d/%d/2024\n", date, month);
        for (int i = 0; i < 5; i++) {
            int randomLocationIndex = rand() % 9;
            int otherAvailability = rand() % 99 + 1;
            int otherPrice = rand() % 4001 + 1000;
            
            printf("\n%d. Location: %s\n", i+1, locations[randomLocationIndex]);
            printf("   Destination: %s\n", locations[rand() % 9]);
            printf("   Availability: %d%%\n", otherAvailability);
            printf("   Price: $%d\n", otherPrice);
        }
    } else if (strcmp(confirm, "No") == 0) {
        printf("Booking Cancelled.\n");
    } else {
        printf("Invalid choice. Booking Cancelled.\n");
    }
}
