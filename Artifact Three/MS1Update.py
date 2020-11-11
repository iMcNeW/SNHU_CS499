import json
import pprint
from bson import json_util
from pymongo import MongoClient

connection = MongoClient('localhost', 27017)
db = connection['city']
collection = db['inspections']

def insert_document(document):
  try:
    collection.update_one({"business_name" : "ARMY Training"}, 
                          {"$set":{"business_name" : "ARMY Training Camp",
                                   "date" : "July 23 2020",
                                   "result" : "Violation Issued"}})
    inspections_data = collection.find_one({"id" : "25612-2020-ARMY"})
    pprint.pprint(inspections_data)
    print("Update Succesful")
    
  except ValidationError as ve:
      abort(400, str(ve))
      return result
    
def main():
    myDocument = {"keyName": "test value data"}
    
    
    print insert_document(myDocument)
    
main()