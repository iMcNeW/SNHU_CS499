import json
import pprint
from bson import json_util
from pymongo import MongoClient

# Establish connection to MongoClient to utilize MongoDB
connection = MongoClient('localhost', 27017)
db = connection['city']
collection = db['inspections']

# Create operation - Allows you to create a new document
def create_new_document():
  print("Enter id")
  id = str(raw_input())
  print("Enter certificate number")
  cert = str(raw_input())
  print("Enter business name")
  business = str(raw_input())
  print("Enter date")
  date = str(raw_input())
  print("Enter result")
  result = str(raw_input())
  print("Enter sector")
  sector = str(raw_input())
  print("Enter address")
  print("Enter city")
  city = str(raw_input())
  print("Enter zip")
  zip = str(raw_input())
  print("Enter street")
  street = str(raw_input())
  print("Enter number")
  number = str(raw_input())
  try:
    inspections_data = {
      "id" : id,
      "certificate_number" : cert,
      "business_name" : business,
      "date" : date,
      "result" : result,
      "sector" : sector,
      "address" : {
      "city" : city,
      "zip" : zip,
      "street" : street,
      "number" : number
      }
    }
    result = collection.insert_one(inspections_data)
    print('Record Succesfully Added: {0}'.format(result.inserted_id))
    
    if inspections_data == True:
      print(False)
    else:
      print(True)
    
  except ValidationError as ve:
      abort(400, str(ve))
      return result

# Read operation - Allows you to search and display a document
def read_document():
  try:
    print("Enter ID")
    ID = str(raw_input())
    inspections_data = collection.find_one({"id" : ID})
    
    if inspections_data == None:
        print("Record not found")
    else:
        print("Record found\n")
        print("Current record details for " + ID)
        pprint.pprint(inspections_data)
  
  except ValidationError as ve:
    abort(400, str(ve))
    return result

# Update operation - Allows you to update an existing document
def update_document():
  print("Enter ID")
  ID = str(raw_input())
  print("\nCurrent record details for " + ID)
  inspections_data = collection.find_one({"id" : ID})
  pprint.pprint(inspections_data)
    
  print("\nWould you like to update this record? (Y or N)")
  
  while True:
    choice = str(raw_input())
    
    if choice == "Y":
      print("Enter certificate number")
      cert = str(raw_input())
      print("Enter business name")
      business = str(raw_input())
      print("Enter date")
      date = str(raw_input())
      print("Enter result")
      result = str(raw_input())
      print("Enter sector")
      sector = str(raw_input())
      print("Enter address")
      print("Enter city")
      city = str(raw_input())
      print("Enter zip")
      zip = str(raw_input())
      print("Enter street")
      street = str(raw_input())
      print("Enter number")
      number = str(raw_input())
      try:
        collection.update_one({"id" : ID}, 
                              {"$set":{"certificate_number" : cert,
                                       "business_name" : business,
                                       "date" : date,
                                       "result" : result,
                                       "sector" : sector,
                                       "address" : {
                                         "city" : city,
                                         "zip" : zip,
                                         "street" : street,
                                         "number" : number}}})
      
        inspections_data = collection.find_one({"id" : ID})
        print("\nUpdated record for " + ID)
        pprint.pprint(inspections_data)
        print("Update Succesful\n")
        break
        
      except ValidationError as ve:
        abort(400, str(ve))
        return result
      
    elif choice == "N":
      print("Goodbye! Back to the main menu.")
      break
      
    else:
      print("\nInvalid Selection, enter Y or N!\n")

# Delete operation - Allows you to delete an existing document
def delete_document():
  print("Enter ID")
  ID = str(raw_input())
  print("\nCurrent record details for " + ID)
  inspections_data = collection.find_one({"id" : ID})
  pprint.pprint(inspections_data)
    
  print("\nWould you like to delete this record? (Y or N)")
  
  while True:
    choice = str(raw_input())
    
    if choice == "Y":
      try:
        if inspections_data == None:
          print("ID not found. Please try again\n")
          break
        else:
          collection.delete_one({"id" : ID})
          print("Inspection Data Deleted Succesfully!")
          break

      except ValidationError as ve:
        abort(400, str(ve))
        return result

    elif choice == "N":
      print("Goodbye! Back to the main menu.")
      break

    else:
      print("\nInvalid Selection, enter Y or N!\n")

# Main menu - Allows a user to choose one of the CRUD operations
def mainMenu():
  while True:
    selection = str(raw_input(
      '\nPlease select an option below: '
      '\n1 Create a new record.'
      '\n2 Search and display record by id.'
      '\n3 Update record by id.'
      '\n4 Delete record by id.'
      '\n9 Quit\n\n'))
      
    if selection == '1':
      create_new_document()
    elif selection == '2':
      read_document()
    elif selection == '3':
      update_document()
    elif selection == '4':
      delete_document()
    elif selection == '9':
      quit()
    else:
      print('\nInvalid selection! \n')
      

mainMenu()