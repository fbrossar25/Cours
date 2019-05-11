import { PostService } from './../../../shared/services/post.service';
import { Component, OnInit, OnDestroy } from '@angular/core';
import {take} from 'rxjs/operators';
import { Observable, Subscription } from 'rxjs';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent implements OnInit, OnDestroy {
  posts: any[];
  postsSubscription: Subscription;
  constructor(private postService: PostService) { }

  ngOnInit() {
    this.postsSubscription = this.postService.getPosts().subscribe((data: any[]) => {
      this.posts = data;
      console.log(this.posts);
    });
  }

  ngOnDestroy() {
    console.log('posts unsubscribed');
    this.postsSubscription.unsubscribe();
  }

}
