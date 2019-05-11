import { VersionService } from './../../../shared/services/version.service';
import { Component, OnInit } from '@angular/core';
import {take, takeWhile} from 'rxjs/operators';

@Component({
  selector: 'app-footer',
  templateUrl: './footer.component.html',
  styleUrls: ['./footer.component.scss']
})
export class FooterComponent implements OnInit {

  version: number;
  constructor(private versionService: VersionService) {

  }

  ngOnInit() {
    this.versionService.getObservable()
    .pipe(
      takeWhile((i) => i < 10),
      take(5)
    ).subscribe((i) => this.version = i);
  }

}
