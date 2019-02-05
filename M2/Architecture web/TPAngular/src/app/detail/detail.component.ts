import { Component, OnInit } from '@angular/core';
import {ActivatedRoute } from '@angular/router';
import {DataDetail} from '../model/dataDetail';
import {Detail} from '../model/Detail';

import {ComapiService} from '../comapi.service';



@Component({
  selector: 'app-detail',
  templateUrl: './detail.component.html',
  styleUrls: ['./detail.component.css']
})
export class DetailComponent implements OnInit {

  id : number = 0;
  detail : Detail;
  constructor(private route: ActivatedRoute,private comapi: ComapiService) { }

  ngOnInit() {
    this.id = +this.route.snapshot.paramMap.get('id');
    this.comapi.getListCryptoDetail(this.id).subscribe(d => { this.detail =  d.data; console.log(this.detail);});

  }

}
