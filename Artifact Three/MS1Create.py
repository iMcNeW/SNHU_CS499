import json
from bson import json_util
from pymongo import MongoClient

connection = MongoClient('localhost', 27017)
db = connection['city']
collection = db['inspections']

def insert_document(document):
    try:
      inspections_data = {
        "id" : "25612-2020-ARMY",
        "certificate_number" : 3362547,
        "business_name" : "ARMY Training",
        "date" : "July 22 2020",
        "result" : "No Violation Issued",
        "sector" : "Trainer",
        "address" : {
        "city" : "Elliston",
        "zip" : 24087,
        "street" : "Trooper LN.",
        "number" : 6547
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
    
def main():
    myDocument = {"keyName": "test value data"}
    
    
    print insert_document(myDocument)
    
main()