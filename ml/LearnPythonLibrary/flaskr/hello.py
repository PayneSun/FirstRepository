'''
    hello.py
'''


from flask import Flask, url_for, request
app = Flask(__name__)


####################################
@app.route('/')
def index():
    return 'Welcome Flask!'


####################################
@app.route('/hello')
def hello_world():
    return 'Li Wei is a puppy!'


####################################
@app.route('/user/<username>')
def show_user_profile(username):
    # show the user profile for that user
    return 'User %s' % username


####################################
@app.route('/post/<int:post_id>')
def show_post(post_id):
    # show the post with the given id, the id is an integer
    return 'Post %d' % post_id


####################################
@app.route('/login', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        print 'POST'
    else:
        print 'GET'



def application(environ, start_response):
    start_response('200 OK', [('Content-Type', 'text/html')])
    return '<h1>Hello, World!</h1>'






####################################
if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True)