from flask import jsonify
import pymysql as sql
from flask import render_template
from app import app

@app.route('/', methods=['GET'])
def route_intro():
    return render_template("intro.html")

@app.route('/register', methods=['GET'])
def route_register():
    return render_template("register.html")

@app.route('/login', methods=['GET'])
def route_login():
    return render_template("login.html")

@app.route('/user/<username>', methods =['GET'])
def route_user(username):
    result = ""
    try:
        connect = sql.connect(host='localhost',
                              unix_socket='/var/run/mysqld/mysqld.sock',
                              user='user',
                              passwd='password',
                              db='epytodo'
                              )
        cursor = connect.cursor()
        cursor.execute('INSERT INTO user(username) VALUES(\"'+username+'\");')
        cursor.execute("SELECT * from  user")
        result = cursor.fetchall()
        connect.commit()
        cursor.close()
        connect.close()
    except Exception as e :
        print("Caught an exception: ", e)
    return jsonify(result)


# @app.route('/user')
# def      route_all_users():
#     result = ""
#     try:
#         ## We’re  creating  connection  between  our  mysql  server  and our  app
#         connect = sql.connect(host='localhost',
#                               unix_socket='/var/run/mysqld/mysqld.sock',
#                               user='brioche',
#                               passwd='salut',
#                               db='noe'
#                               )
#         ## We’re retrieving a "pointer" aka "cursor" to our database
#         cursor = connect.cursor()
#         ## We’re executing a SQL command,
#         ## assuming that all tables are already created
#         cursor.execute("SELECT * from  user")
#         ## We’re retrieving all results
#         result = cursor.fetchall()
#         ## We’re closing our cursor and our connection
#         cursor.close()
#         connect.close()
#     except Exception as e :
#         print("Caught an exception: ", e)
#     ## We’re sending the data
#     return jsonify(result)