import json
from bson import json_util
from pymongo import MongoClient

connection = MongoClient('localhost', 27017)
db = connection['city']
collection = db['inspections']

def insert_document(document):
  try:
    collection.delete_one({"business_name" : "ARMY Training Camp"})
    inspections_data = collection.find_one({"id" : "25612-2020-ARMY"})
    
    if inspections_data == None:
      print('Inspection Data Deleted')
    else:
      print('Try again')

  except ValidationError as ve:
      abort(400, str(ve))
      return result
def main():
    myDocument = {"keyName": "test value data"}
    print insert_document(myDocument)
    
main()
