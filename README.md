# collect-feedback

Most major websites collect feedback from their customers in order to improve the quality of their services. The most common form of user feedback is ratings. For example, Amazon.com collects users’ ratings of books, Imdb.com collects movie ratings and Booking.com gathers users’ rating of hotels. 

A rating consists mainly of three important pieces of information: 
1. The user ID: this is the ID of the user who gave the rating. 
2. The item ID: this is the ID of the item being rated. For example, the item can be a book, a movie or a hotel. 
3. The rating value: this is a numerical value that is usually an integer ranging from 1 to 5, where 1 is the lowest rating (user not satisfied) and 5 is the highest rating (user very satisfied). 

The goal in this project is to write a program that reads a list of ratings, stores them in memory and answers a number of queries. Examples of queries are: What is the rating given by user i to item j? What is the average rating of item j? What is (are) the highest rated item(s)? 
